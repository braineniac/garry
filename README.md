# ROS Project Garry 

My bachelor's project at TU Vienna. A small snail-like robot that uses orbslam2.  

This repo is basically a meta package. The actual ROS packages are:  
https://github.com/braineniac/garry-robot.git  
https://github.com/braineniac/garry-firmware.git  
https://github.com/braineniac/garry-description.git   
https://github.com/braineniac/ros_mpu6050_node.git  

## Hardware  

Raspberry Pi 3 Model B  Rev 1.2
Arduino Uno Rev3  
Arduino Motor Shield Rev3    
Raspberry Pi Night Vision Camera Module(OV5647 5MP Webcam Sensor)  
Logitech C905 Webcam
MPU-6050  
Logitech Dual Action Gamepad
2 green LEDs  
2x generic 5V DC motors  
2x EMAX ES08MA II 12g Mini Metal Gear Analog Servo

## Installation

The catkin workspace is managed with wstool and rosinstall

### Dependencies

apt: libglew-dev autoconf  python-pip  hostapd dnsmasq  
ros-melodic: rosserial_arduino pcl_ros joy

### Installation

Write raspbian to an SD card for the Raspberry Pi 3 Model B.  

Follow [this][1] to compile ROS melodic on raspbian.  

Install deps:  
`sudo apt install libglew-dev autoconf python-pip -y`  

I used catkin from pip because the stretch version is old and has this [error][1]  
`pip install catkin catkin-tools rosdep`  

In the compiled ros directory add the ros deps:  
`wstool merge -t src PATH_TO_GARRY/rosinstall/melodic-pcl-ros.rosinstall`  
`wstool merge -t src PATH_TO_GARRY/rosinstall/melodic-joy.rosinstall`  
`wstool merge -t src PATH_TO_GARRY/rosinstall/melodic-rosserial_arduino.rosinstall`  
`wstool update -t src`  

Install deps:  
`rosdep install --from-paths src --ignore-src --rosdistro melodic -y --os:debian:stretch`

Compile ROS with deps:  
`./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release -q`  

Create workspace and add sources:  
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

wlan0 is configured as an access point and connected to the bridge br0. Network access is routed through eth0, 
so it can access the internet when eth0 is connected and your are connected to the wifi. 
`sudo cp PATH_TO_GARRY/wifi/interfaces /etc/network/interfaces`  
`sudo mkdir /etc/hostapd`  
`sudo cp PATH_TO_GARRY/wifi/hostapd.conf /etc/hostapd/`  

Edit the DAMON_CONF in /etc/default/hostapd to /etc/hostapd/hostapd.conf  
`sudo cp PATH_TO_GARRY/wifi/dhcpcd.conf /etc/`  
`sudo cp PATH_TO_GARRY/wifi/dnsmasq.conf /etc/`  
`sudo systemctl enable hostapd dnsmasq dhcpcd`  

Then reboot and it should work. The default password is g4rryn3t and can be changed in the dnsmasq.conf file.  



[1]: http://wiki.ros.org/melodic/Installation/Source
[2]: https://answers.ros.org/question/294780/ubuntu18-and-ros-melodic-catkin-error-importerror-no-module-named-terminal_color/
