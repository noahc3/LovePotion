#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
define n


endef

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment.$nexport DEVKITPRO=<path to>/devkitpro")
endif

ifeq ($(strip $(LOVEPOTION_ELF)),)

export ERR_MSG := \
$nPlease set LOVEPOTION_ELF in your environment.\
$nThis should be the path to your Love Potion projects.\
$nDo *NOT* save the *.elf file anywhere else.\
$nexport LOVEPOTION_ELF=<path to>/LovePotion.elf
$(error $(ERR_MSG))
endif

ifeq ($(strip $(shell which rsync)),)
export ERR_MSG := \
$nThe program 'rsync' is not installed.\
$nPlease install it for your Operating System.\
$nWindows: 'pacman -S rsync'\
$nLinux: <package installer command> rsync
$(error $(ERR_MSG))
endif

TOPDIR = $(CURDIR)
include $(DEVKITPRO)/libnx/switch_rules

#---------------------------------------------------------------------------------
# TARGET is the name of the output files
# BUILD is the directory where object files & intermediate files will be placed
# ROMFS is the directory containing data to be added to RomFS, relative to the Makefile (Optional)
# SOURCE is the directory containing your LOVE game (can be external from this directory)
# An external project could be such as ../../MyProject

# APP_TITLE is the name of the app stored in the .nacp file (Optional)
# APP_AUTHOR is the author of the app stored in the .nacp file (Optional)
# APP_VERSION is the version of the app stored in the .nacp file (Optional)
# APP_TITLEID is the titleID of the app stored in the .nacp file (Optional)
# ICON is the filename of the icon (.jpg), relative to the project folder.
#   If not set, it attempts to use one of the following (in this order):
#     - <Project name>.jpg
#     - icon.jpg
#     - <libnx folder>/default_icon.jpg
#---------------------------------------------------------------------------------
TARGET		:= $(notdir $(CURDIR))
BUILD		:= $(TOPDIR)

SOURCE		:= source
ROMFS       := game
LOVEPOTION	:= $(LOVEPOTION_ELF)

APP_TITLE	:= Löve Potion
APP_AUTHOR	:= TurtleP
APP_VERSION	:= 1.0
APP_TITLEID	:= 1043

ICON		:= icon.jpg

export OUTPUT	:=	$(TARGET)
export TOPDIR	:=	$(CURDIR)

ifeq ($(strip $(ICON)),)
	icons := $(wildcard *.jpg)
	ifneq (,$(findstring $(TARGET).jpg,$(icons)))
		export APP_ICON := $(TOPDIR)/$(TARGET).jpg
	else
		ifneq (,$(findstring icon.jpg,$(icons)))
			export APP_ICON := $(TOPDIR)/icon.jpg
		endif
	endif
else
	export APP_ICON := $(TOPDIR)/$(ICON)
endif

.PHONY: $(BUILD) clean all

#---------------------------------------------------------------------------------
all: $(BUILD)

$(BUILD):
	@[ -d game ] || mkdir -p game
	@rsync -a --exclude=".[!.]*" $(SOURCE)/* game

#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(TARGET).pfs0 $(TARGET).nso $(TARGET).nro $(TARGET).nacp game

.PHONY:	all

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
all	: $(OUTPUT).nacp $(OUTPUT).nro

$(OUTPUT).nacp:
	@nacptool --create "$(APP_TITLE)" "$(APP_AUTHOR)" "$(APP_VERSION)" $@

$(OUTPUT).nro : $(OUTPUT).nacp
	@elf2nro $(LOVEPOTION) $(OUTPUT).nro --icon=$(APP_ICON) --nacp=$(OUTPUT).nacp --romfsdir=$(ROMFS)