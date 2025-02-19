#include <memory>  // for allocator, __shared_ptr_access, shared_ptr
#include <string>  // for string, basic_string
#include <vector>  // for vector
#include <thread>

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Radiobox, Horizontal, Menu, Renderer, Tab
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, separator, hbox, operator|, border

using namespace ftxui;

// This is a helper function to create a button with a custom style.
// The style is defined by a lambda function that takes an EntryState and
// returns an Element.
// We are using `center` to center the text inside the button, then `border` to
// add a border around the button, and finally `flex` to make the button fill
// the available space.
ButtonOption Style() {
  auto option = ButtonOption::Animated(Color::Green);
  option.transform = [](const EntryState& s) {
    auto element = text(s.label);
    if (s.focused) {
      element |= bold;
    }
    return element | center | borderEmpty | flex;
  };
  return option;
}

std::vector<std::string> tab_values
{
    "LampControl"
};
int command_selected = 0;

auto tab_menu = Menu(&tab_values, &command_selected);

// std::vector<std::string> cameracontrolentries
// {
//     "Coming Soon"
// };
// int camera_control_command = 0;

std::vector<std::string> lampcontrolsettings
{
    "Light ON",
    "Light OFF"
    // "Intensity"
};
int lamp_control_command = 2;

// std::vector<std::string> panandtiltcontrol
// {
//     "COMING SOON",
// };
// int pan_tilt_command = 0;

