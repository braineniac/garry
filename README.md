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

apt: libglew-dev autoconf hostapd dnsmasq  
ros-melodic: rosserial_arduino pcl_ros

### Installation

#### ROS desktop compilation

Write raspbian to an SD card for the Raspberry Pi 3 Model B.  

Enable the debian buster repo, but do NOT upgrade the system!  

Follow [this][1] to compile ROS melodic desktop on raspbian. With slight alterations:  

Install deps:  
`rosdep install --from-paths src --ignore-src --rosdistro melodic -y --os=debian:stretch`  

Create ROS install directory:  
`sudo mkdir -p /opt/ros/melodic`  
`sudo chown $USER /opt/ros/melodic`  

Fix catkin/cmake issue by replacing the catkin with the latest git source and compile cmake with the referenced commit until this gets fixed. Refs: [1][3] [2][4] [3][5]    

Compile ROS with deps:  
`./src/catkin/bin/catkin_make_isolated --install  --install-space /opt/ros/melodic -DCMAKE_BUILD_TYPE=Release -q`  

Source workspace with:  
`echo "source /opt/ros/melodic/install_isolated/setup.bash" >> /home/$USER/.bashrc`  
`bash`  

#### Swap setup

You will need the extra swap space for compiling pcl_ros.  

Get an empty USB drive, in this case it shows up as /dev/sda. Create a partition on it and format it as ext4.  

Add an entry to /etc/fstab with the PARTUUID of the USB and automount to /swap.

Edit /etc/dphys-swapfile and uncomment all options and leave them empty(this will override all swap restrictions put in place), except the CONF_SWAPFILE=/swap/swapfile.  

Create swapfile in /swap:  
`sudo dd if=/dev/zero of=/swap/swapfile bs=1G count=7 status=progress`  
`sudo mkswap /swap/swapfile`  

Disable dphys-service:  
`sudo systemctl disable dphys-swapfile`    
`sudo systemctl stop dphys-swapfile`  

Now you can mount the swapfile:  
`sudo swapon /swap/swapfile`  

Check if it worked with:
`free -m`  



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
[3]: https://github.com/ros/catkin/pull/975
[4]: https://gitlab.kitware.com/cmake/cmake/merge_requests/2570/commits
[5]: https://gitlab.kitware.com/cmake/cmake/issues/18638
