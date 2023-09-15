LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE := jsoncpp
# jsoncpp defines
jsoncpp_includes := $(LOCAL_PATH)/include $(LOCAL_PATH)/src/lib_json
jsoncpp_export_includes := $(jsoncpp_includes)
jsoncpplib_json_src_files := \
    json_reader.cpp \
    json_value.cpp \
    json_writer.cpp
jsoncpplib_json_src_files := $(jsoncpplib_json_src_files:%=src/lib_json/%)


LOCAL_C_INCLUDES := $(jsoncpp_includes)
LOCAL_EXPORT_C_INCLUDES := $(jsoncpp_export_includes)
LOCAL_STATIC_LIBRARIES := libcxx
LOCAL_SRC_FILES := $(jsoncpplib_json_src_files)
include $(BUILD_STATIC_LIBRARY)
