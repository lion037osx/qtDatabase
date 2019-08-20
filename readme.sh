#
#ssh-keygen -t rsa -b 4096 -C  "mail@yahoo.com"

all:
	chmod -R 777 *
	chmod 777 *

help:
	@+echo ""
	@+echo ""
	@+echo "*********************************Help GIT******************************************"
	@+echo ""
	@+echo "make clone"
	@+echo "		git clone https://github.com/lion037osx/qt.git"
	@+echo "make push"
	@+echo "		git push https://github.com/lion037osx/qt.git"
	@+echo "make pull"
	@+echo "		git pull https://github.com/lion037osx/qt.git"
	@+echo "make commit"
	@+echo "		git commit -m \"update\""
	@+echo "make add"
	@+echo "		git add ."
	@+echo "		git commit - m \"update\""
	@+echo "		git push origin master"
	@+echo ""
	@+echo ""
	@+echo "		Copyrigth by Leo"
	@+echo ""
	@+echo ""

clone:
	git clone https://github.com/lion037osx/qt.git
push:
#	git add.
#	git commit -m "update"
#	git push origin master 
#	git push https://github.com/lion037osx/qt.git
	git push origin
pull:
#	git add .
#	git commit -m "upgrade"
#	git pull origin master
	#git pull git push https://github.com/lion037osx/qt.git
	git pull origin
commit:
	git commit -m "update"
add:
	git add .
status:
	git status
	git remote -v

merge:
	git merge
	#git remote -v

upgrade:
	git add .
	git commit -m "update"
	git push origin master

update:
	git pull --all

fetch:
	git fetch origin
init:
	echo "# qtPnt" >> README.md
	git init
	git add README.md
	git commit -m "app explorer img"
	git remote add origin https://github.com/lion037osx/qt.git
	git push -u origin master
