LOCAL_PATH := $(call my-dir)

# common code

include $(CLEAR_VARS)
LOCAL_MODULE := common
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
LOCAL_STATIC_LIBRARIES := libcxx jsoncpp
LOCAL_SRC_FILES :=\
    fileutils.cpp \
    fdutils.cpp
include $(BUILD_STATIC_LIBRARY)