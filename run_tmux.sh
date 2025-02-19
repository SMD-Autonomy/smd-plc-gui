#!/bin/sh

# Set session name
SESSION="smd-plc-gui"
SESSIONEXISTS=$(tmux list-sessions | grep $SESSION)

# Only create tmux session if it doesn't already exist
if [ "$SESSIONEXISTS" = "" ]
then
    # Start new session with our name
    tmux new-session -d -s $SESSION

    # Split the window into two vertical panes (left and right)
    tmux split-window -h

    # Select the right pane and split it horizontally into two stacked panes
    tmux select-pane -R
    tmux split-window -v

    # Run the camera server (OPCUA) in Pane 1 (left top)
    tmux send-keys -t $SESSION:0.0 'cd app; ./objs/x64Linux4gcc7.3.0/pidcontrol_subscriber -d 6' C-m  
        
    # Run the camera server (OPCUA) in Pane 2 (right top)
    tmux send-keys -t $SESSION:0.1 'cd app; ./objs/x64Linux4gcc7.3.0/pidcontrol_publisher -d 6' C-m  

    # Run the camera controller (DDS) in Pane 2 (right bottom)
    tmux send-keys -t $SESSION:0.2 'sleep 3; ./gateway-opcua/bin/rtiddsopcuagateway -cfgFile plc_control_service.xml -cfgName PLCcontrolService' C-m  

fi

# Attach session, on the main window
tmux attach-session -t $SESSION:0