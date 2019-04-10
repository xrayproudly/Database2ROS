# Database2ROS

Retrieving Data from a MYSQL Database and transferring it into a ROS based System. This data is then manipulated and published to a ROS network.

## Getting Started

This must be done to get the current version running.

### System Environment

The following software is recommended:

```
Linux Ubuntu 18.04.2 (64bit)
Visual Studio Code
ROS Melodic Morenia
MySQL 5.7.25
MySQL C++ Connector 8.0
```

### Installing Software

First install Ubuntu 18.04.2 (64bit), then update everytyhing with:

```
$ sudo apt-get update
$ sudo apt-get upgrade
```

#### Installing Visual Studio Code

Visit the following Website and follow the Instructions:

https://linuxize.com/post/how-to-install-visual-studio-code-on-ubuntu-18-04/

#### Installing ROS Melodic Morenia

Visit the following Website and follow the Instructions:

http://wiki.ros.org/melodic/Installation/Ubuntu

#### Installing MySQL

Visit the following Website and follow the Instructions:

https://dev.mysql.com/doc/mysql-apt-repo-quick-guide/en/

#### Installing MySQL C++ Connector 8.0

Set up your ROS Workspace like stated on the following Website:

http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment

Install the boost library with the following command:

```
$ sudo apt-get install libboost-all-dev
```

Change to your source folder (../src) inside your workspace folder (here: catkin_ws)

```
$ cd ~/catkin_ws/src
```

Initialize your Git with

```
$ git init
```

Clone the MySQL Repository into your /src folder

```
$ git clone https://github.com/mysql/mysql-connector-cpp.git
```

Checkout the master branch of the Repository with

```
cd mysql-connector-cpp
git checkout master
```

Update your Git submodules with

```
$ git submodule update --init
```

Configure the Connector/C++ with "PATH_TO_BOOST" set as the path to your boost directory (default: /usr/include/boost)

```
$ cmake . -DWITH_BOOST=PATH_TO_BOOST -DWITH_JDBC=ON
```

Build the Connector/C++

```
$ cmake --build . --config debug
```

Install the Connector/C++

```
$ cmake --build . --target install
```










