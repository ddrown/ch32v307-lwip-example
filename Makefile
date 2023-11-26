VENDOR_DIR := ./CH32V307-makefile-example/vendor
EXTRA_INC := -I./CH32V307-makefile-example/vendor -I./lwip/src/Drivers/LWIP/include/ -I./lwip/src/Drivers/LWIP
SRC_DIRS := lwip/src/ src/
include ./CH32V307-makefile-example/Makefile
