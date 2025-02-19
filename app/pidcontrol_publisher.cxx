/*
* (c) Copyright, Real-Time Innovations, 2020.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// alternatively, to include all the standard APIs:
//  <dds/dds.hpp>
// or to include both the standard APIs and extensions:
//  <rti/rti.hpp>
//
// For more information about the headers and namespaces, see:
//    https://community.rti.com/static/documentation/connext-dds/7.3.0/doc/api/connext_dds/api_cpp2/group__DDSNamespaceModule.html
// For information on how to use extensions, see:
//    https://community.rti.com/static/documentation/connext-dds/7.3.0/doc/api/connext_dds/api_cpp2/group__DDSCpp2Conventions.html

#include "application.hpp"  // for command line parsing and ctrl-c
#include "pidcontrol.hpp"
#include "plc_gui.hpp"

unsigned int domain_id; 

bool setLampstatus(std::string status)
{
    bool lampstatus;
    if(status.compare("Light ON")==0){
        // Set the start command
        lampstatus = true;
        return lampstatus;
    }
    else if(status.compare("Light OFF")==0){
        // Set the start command
        lampstatus = false;
        return lampstatus;
    }

}

void run_publisher_application(unsigned int domain_id, std::string status)
{
    // DDS objects behave like shared pointers or value types
    // (see https://community.rti.com/best-practices/use-modern-c-types-correctly)

    // Start communicating in a domain, usually one participant per application
    dds::domain::DomainParticipant participant(domain_id);

    // Create a Topic with a name and a datatype
    dds::topic::Topic< ::LampControl> topic(participant, "LampControl");

    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a DataWriter with default QoS
    dds::pub::DataWriter< ::LampControl> writer(publisher, topic);

    ::LampControl data;
    // Main loop, write data
    while (!application::shutdown_requested){ 
        // Modify the data to be written here
        // data.lampID(static_cast< int32_t>(samples_written));
        bool lampstatus = setLampstatus(status);
        data.count_r(static_cast< bool>(lampstatus));
        std::cout << "Writing ::LampControl " << status << std::endl;

        writer.write(data);

        // Send once every second
        rti::util::sleep(dds::core::Duration(1));
    }
    
}

void publishLampstatus(int lamp_control_command)
{
    if(lamp_control_command==2){
        try {
        run_publisher_application(domain_id, "Light ON");
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
    }
    }
    else {
        try {
            run_publisher_application(domain_id, "Light OFF");
        } catch (const std::exception& ex) {
            // This will catch DDS exceptions
            std::cerr << "Exception in run_publisher_application(): " << ex.what()
            << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{

    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();
    
    domain_id = arguments.domain_id;

    int rowtoggle = 0;
    int positionTargetRowToggle = 0;

    auto tab_container = Container::Tab(
    {
    Radiobox(&lampcontrolsettings, &lamp_control_command),
    },
    &command_selected);

    auto btn_feb_01 = Button("Send command", [&] 
    {
    if(command_selected==0)
    {
        publishLampstatus(lamp_control_command);
    }
    }, Style());

    int row = 0;

    auto buttons = Container::Vertical({
        Container::Horizontal({btn_feb_01}, &row) | flex
    });

    auto container = Container::Horizontal({
        tab_menu,
        tab_container,
        buttons
    });

    auto renderer = Renderer(container, [&] {
    return 
        hbox({
            tab_menu->Render(),
            separator(),
            vbox({
                tab_container->Render(),
                separator(),
                buttons->Render() 
            }) | flex
        }) | border;
    });
    
    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
