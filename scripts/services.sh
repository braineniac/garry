#!/usr/bin/env bash

SYSTEMD=/etc/systemd/system
SYSTMD_LIB=/lib/systemd/system
SERVICES=/home/dan/ws_garry/garry/services

rm -f $SYSTMD_LIB/dnsmasq.service
sudo ln -s $SERVICES/dnsmasq.service $SYSTMD_LIB/dnsmasq.service

rm -f $SYSTEMD/garry-eyes.service
sudo ln -s $SERVICES/garry-eyes.service $SYSTEMD/garry-eyes.service 

rm -f $SYSTEMD/garry-robot.service
sudo ln -s $SERVICES/garry-robot.service $SYSTEMD/garry-robot.service

rm -f $SYSTEMD/garry-joy.service
sudo ln -s $SERVICES/garry-joy.service $SYSTEMD/garry-joy.service 

rm -f $SYSTEMD/imu.service
sudo ln -s $SERVICES/imu.service $SYSTEMD/imu.service 

rm -f $SYSTEMD/meow.service
sudo ln -s $SERVICES/meow.service $SYSTEMD/meow.service 

rm -f $SYSTEMD/roscore.service
sudo ln -s $SERVICES/roscore.service $SYSTEMD/roscore.service 
