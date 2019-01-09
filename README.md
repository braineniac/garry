# ROS Project Garry 

My bachelors project at TU Vienna. A small snail-like robot that uses orbslam2.  

This repo is basically a meta package. The actual ROS packages are:  
https://github.com/braineniac/garry-robot.git  
https://github.com/braineniac/garry-firmware.git  
http://github.com/braineniac/garry-description.git   
https://github.com/braineniac/ros_mpu6050_node.git  

## Hardware  
raspberry pi 3  model B
arduino uno  
arduino motor shield  
rapberry camera module  
logitech webcam  
mpu6050  
2 leds  
2 generic DC motors  
2 stepper motors  

## Installation

The catkin workspace is managed with wstool and rosinstall

### Dependencies

apt: libglew-dev autoconf  python-pip  hostapd dnsmasq
ros-melodic: rosserial_arduino pcl_ros joy

### Installation

I compiled ROS melodic on raspbian, so I used:  
`sudo apt install libglew-dev autoconf python-pip -y`  

I used pip because the stretch version is old and has this [error][1]  
`pip install catkin catkin-tools rosdep`  

In the compiled ros directory add the ros deps:  
`wstool merge -t src PATH_TO_GARRY/rosinstall/melodic-pcl-ros.rosinstall`  
`wstool merge -t src PATH_TO_GARRY/rosinstall/melodic-joy.rosinstall`  
`wstool merge -t src PATH_TO_GARRY/rosinstall/melodic-rosserial_arduino.rosinstall`  
`wstool update -t src`  

Install deps:  
`rosdep install --from-paths src --ignore-src --rosdistro melodic -y --os:debian:stretch`

Compile ROS with the added deps:  
`./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release -q`  

Create workspace and added sources:  
`mkdir -p ros_garry/src`  
`cd ros_garry`  
`wstool init -t src`
`wstool merge -t src PATH_TO_GARRY/rosinstall/robot.rosinstall`  
`wstool merge -t src PATH_TO_GARRY/rosinstall/orbslam2.rosinstall`  
`wstool update -t src`  

### WIFI access point setup

Install hostapd and dnsmasq  
`sudo apt install hostapd dnsmasq -y`  

Stop the services for now:  
`sudo systemctl stop dnsmasq hostapd`  

wlan0 is configured as an access point and connected to the bridge br0. Network access is routed through eth0, so it can access the internet when eth0 is connected.  
`sudo cp PATH_TO_GARRY/wifi/interfaces /etc/network/interfaces`  
`sudo mkdir /etc/hostapd`  
`sudo cp PATH_TO_GARRY/wifi/hostapd.conf /etc/hostapd/`  

Edit the DAMON_CONF in /etc/default/hostapd to /etc/hostapd/hostapd.conf  
`sudo cp PATH_TO_GARRY/wifi/dhcpcd.conf /etc/`  
`sudo cp PATH_TO_GARRY/wifi/dnsmasq.conf /etc/`  
`sudo systemctl enable hostapd dnsmasq dhcpcd`  

Then reboot and it should work. The default password is g4rryn3t and can be changed in the dnsmasq.conf file.  




[1]: https://answers.ros.org/question/294780/ubuntu18-and-ros-melodic-catkin-error-importerror-no-module-named-terminal_color/
