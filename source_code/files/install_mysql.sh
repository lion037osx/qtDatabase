#!/bin/bash

apt-get install libmysqlclient20 -y
apt-get install libmysqlclient-dev -y
apt-get install libdbd-mysql-perl libmldbm-perl libnet-daemon-perl libsql-statement-perl libscalar-number-perl -y

ln -s /usr/lib/x86_64-linux-gnu/libmysqlclient.so /usr/lib/x86_64-linux-gnu/libmysqlclient_r.so
dpkg -i libmysqlclient18_5.6.25-0ubuntu1_amd64.deb

apt-get install libdbd-mysql-perl -y
apt-get install libmysqlclient-dev -y
apt-get install libmysqlclient18:amd64 -y
apt-get install libqt5sql5-mysql:amd64 -y
apt-get install mysql-client-5.5 -y
apt-get install mysql-client-core-5.5 -y
apt-get install mysql-common -y
apt-get install mysql-server  -y
apt-get install mysql-server-5.5 -y
apt-get install mysql-server-core-5.5 -y
apt-get install mysqltuner  -y
apt-get install libmysqlclient-dev -y

apt-get update -y
apt-get upgrade -y

