#!/usr/bin/env bash

sudo rm /etc/network/interfaces
sudo ln -s /home/dan/ws_garry/garry/wifi/interfaces /etc/network/interfaces


sudo rm /etc/hostapd/hostapd.conf
sudo ln -s /home/dan/ws_garry/garry/wifi/hostapd.conf /etc/hostapd/hostapd.conf

sudo rm /etc/dhcpcd.conf
sudo ln -s /home/dan/ws_garry/garry/wifi/dhcpcd.conf /etc/dhcpcd.conf

sudo rm /etc/dnsmasq.conf
sudo ln -s /home/dan/ws_garry/garry/wifi/dnsmasq.conf /etc/dnsmasq.conf

sudo rm /etc/default/hostapd
sudo ln -s /home/dan/ws_garry/garry/wifi/hostapd /etc/default/hostapd
