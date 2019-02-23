# ROS Project Garry 

My bachelor's project at TU Vienna. A small snail-like robot with localization.  

This repo is basically a meta package. The actual ROS packages are:  
https://github.com/braineniac/rpi_mpu6050.git  
https://github.com/braineniac/garry-robot.git  
https://github.com/braineniac/garry-firmware.git  
https://github.com/braineniac/garry-description.git   

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

## Dependencies

apt: libglew-dev autoconf hostapd dnsmasq  
ros-kinetic: rosserial_arduino pcl_ros joy  

## Swap setup

You will need the extra swap space for compiling.  

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

## WIFI access point setup

Replace the firmware with the [new][7] one.  

Install hostapd and dnsmasq  
`sudo apt install hostapd dnsmasq dhcpcd5 -y`  

Stop the services for now:  
`sudo systemctl stop dnsmasq hostapd`  

Run:  
`./scripts/wifi.sh`  
`./scripts/services.sh`  

Then reboot and it should work. The default password is g4rryn3t and can be changed in the dnsmasq.conf file.  

## Workspace setup  

Create new folder:    
`mkdir -p ros_ws/src && cd ros_ws`

Setup workspace with wstool:  
`wstool init src GARRY_DIR/.rosinstall`  

Compile with:  
`catkin build`  


[1]: http://wiki.ros.org/melodic/Installation/Source
[2]: https://answers.ros.org/question/294780/ubuntu18-and-ros-melodic-catkin-error-importerror-no-module-named-terminal_color/
[3]: https://github.com/ros/catkin/pull/975
[4]: https://gitlab.kitware.com/cmake/cmake/merge_requests/2570/commits
[5]: https://gitlab.kitware.com/cmake/cmake/issues/18638
[6]: https://www.raspberrypi.org/documentation/configuration/wireless/access-point.md
[7]: https://github.com/RPi-Distro/firmware-nonfree
