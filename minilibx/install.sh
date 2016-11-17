#!/bin/bash

# Show prompt function
function showPrompt()
{
	if [ "$PROMPT" = true ] ; then
		echo -e "\n\n"
			read -p "${GREEN}Press enter to continue...${NC}"
			fi
}

# Set colors
GREEN=`tput setaf 2`
NC=`tput sgr0` # No Color

# Set to true to also build and install apps
APPS=true

# Set to true to pause after each build to verify successful build and installation
PROMPT=true

# Install Requirements
sudo apt update

echo -e "\n\n${GREEN}Installing dependencies...${NC}"
sudo apt -y install clang git ninja cmake libffi-dev libxml2-dev \
		 libgnutls28-dev libicu-dev libblocksruntime-dev libkqueue-dev libpthread-workqueue-dev autoconf libtool \
		 libjpeg-dev libtiff-dev libffi-dev libcairo-dev libx11-dev:i386 libxt-dev libxft-dev

		 if [ "$APPS" = true ] ; then
		 sudo apt -y install curl
		 fi

# Create build directory
		 mkdir GNUstep-build
		 cd GNUstep-build

# Set clang as compiler
		 export CC=clang
		 export CXX=clang++

# Checkout sources
		 echo -e "\n\n${GREEN}Checking out sources...${NC}"
		 git clone https://github.com/nickhutchinson/libdispatch.git
		 git clone https://github.com/gnustep/libobjc2.git
		 git clone https://github.com/gnustep/make
		 git clone https://github.com/gnustep/base.git
		 git clone https://github.com/gnustep/gui.git
		 git clone https://github.com/gnustep/back.git

		 if [ "$APPS" = true ] ; then
		 git clone https://github.com/gnustep/projectcenter.git
		 git clone https://github.com/gnustep/gorm.git
		 git clone https://github.com/gnustep/gworkspace.git
		 curl -O ftp://ftp.gnustep.org/pub/gnustep/usr-apps/SystemPreferences-1.2.0.tar.gz
		 tar xvzf SystemPreferences-1.2.0.tar.gz
		 fi

		 showPrompt

# Build GNUstep make first time
		 echo -e "\n\n"
		 echo -e "${GREEN}Building GNUstep-make for the first time...${NC}"
		 cd make
		 ./configure --enable-debug-by-default --with-layout=gnustep --enable-objc-nonfragile-abi --enable-objc-arc
		 make -j8
		 sudo -E make install

		 . /usr/GNUstep/System/Library/Makefiles/GNUstep.sh
		 echo ". /usr/GNUstep/System/Library/Makefiles/GNUstep.sh" >> ~/.bashrc

		 showPrompt

# Build libdispatch
		 echo -e "\n\n"
		 echo -e "${GREEN}Building libdispatch...${NC}"
		 cd ../libdispatch
		 rm -Rf build
		 mkdir build && cd build
		 ../configure  --prefix=/usr
		 make
		 sudo make install
		 sudo ldconfig

		 showPrompt

# Build libobjc2
		 echo -e "\n\n"
		 echo -e "${GREEN}Building libobjc2...${NC}"
		 cd ../../libobjc2
		 rm -Rf build
		 mkdir build && cd build
		 cmake ../ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang -DCMAKE_ASM_COMPILER=clang -DTESTS=OFF
		 cmake --build .
		 sudo -E make install
		 sudo ldconfig

		 export LDFLAGS=-ldispatch

		 showPrompt

		 OBJCFLAGS="-fblocks -fobjc-runtime=gnustep-1.8.1"

# Build GNUstep make second time
		 echo -e "\n\n"
		 echo -e "${GREEN}Building GNUstep-make for the second time...${NC}"
		 cd ../../make
		 ./configure --enable-debug-by-default --with-layout=gnustep --enable-objc-nonfragile-abi --enable-objc-arc
		 make -j8
		 sudo -E make install

		 . /usr/GNUstep/System/Library/Makefiles/GNUstep.sh

		 showPrompt

# Build GNUstep base
		 echo -e "\n\n"
		 echo -e "${GREEN}Building GNUstep-base...${NC}"
		 cd ../base/
		 ./configure
		 make -j8
		 sudo -E make install

		 showPrompt

# Build GNUstep GUI
		 echo -e "\n\n"
		 echo -e "${GREEN} Building GNUstep-gui...${NC}"
		 cd ../gui
		 ./configure
		 make -j8
		 sudo -E make install

		 showPrompt

# Build GNUstep back
		 echo -e "\n\n"
		 echo -e "${GREEN}Building GNUstep-back...${NC}"
		 cd ../back
		 ./configure
		 make -j8
		 sudo -E make install

		 showPrompt

		 . /usr/GNUstep/System/Library/Makefiles/GNUstep.sh

		 if [ "$APPS" = true ] ; then
		 echo -e "${GREEN}Building ProjectCenter...${NC}"
		 cd ../projectcenter/
		 make -j8
		 sudo -E make install

		 showPrompt

		 echo -e "${GREEN}Building Gorm...${NC}"
		 cd ../gorm/
		 make -j8
		 sudo -E make install

		 showPrompt

		 echo -e "\n\n"
		 echo -e "${GREEN}Building GWorkspace...${NC}"
		 cd ../gworkspace/
		 ./configure
		 make -j8
		 sudo -E make install

		 showPrompt

		 echo -e "\n\n"
		 echo -e "${GREEN}Building SystemPreferences...${NC}"
		 cd ../SystemPreferences-1.2.0/
		 make -j8
		 sudo -E make install

		 fi

		 echo -e "\n\n"
		 echo -e "${GREEN}Install is done. Open a new terminal to start using.${NC}"
