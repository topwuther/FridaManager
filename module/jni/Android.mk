LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := frida_manager
LOCAL_SRC_FILES := zygisk_main.cpp
LOCAL_STATIC_LIBRARIES := \
    libcxx \
    common \
    jsoncpp \
    fmt
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)
include jni/libcxx/Android.mk
include jni/common/Android.mk
include jni/jsoncpp/Android.mk
include jni/fmt/Android.mk



# If you do not want to use libc++, link to system stdc++
# so that you can at least call the new operator in your code

# include $(CLEAR_VARS)
# LOCAL_MODULE := example
# LOCAL_SRC_FILES := example.cpp
# LOCAL_LDLIBS := -llog -lstdc++
# include $(BUILD_SHARED_LIBRARY)
