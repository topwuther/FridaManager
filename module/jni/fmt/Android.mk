LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE := fmt
# fmt defines
fmt_includes := $(LOCAL_PATH)/include
fmt_export_includes := $(fmt_includes)
fmt_src_files := \
    format.cc
fmt_src_files := $(fmt_src_files:%=src/%)


LOCAL_C_INCLUDES := $(fmt_includes)
LOCAL_EXPORT_C_INCLUDES := $(fmt_export_includes)
LOCAL_STATIC_LIBRARIES := libcxx
LOCAL_SRC_FILES := $(fmt_src_files)
include $(BUILD_STATIC_LIBRARY)
