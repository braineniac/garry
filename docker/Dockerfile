FROM ros:kinetic-ros-base

RUN apt update && apt upgrade -y
COPY . /garry
COPY entrypoint.sh entrypoint.sh
SHELL ["/bin/bash", "-c", "-l"]
RUN . /opt/ros/kinetic/setup.bash && cd /garry && catkin_make --source . && . /garry/devel/setup.bash
ENTRYPOINT ["/entrypoint.sh"]
