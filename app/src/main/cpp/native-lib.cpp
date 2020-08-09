#include <jni.h>
#include <string>
#include <unistd.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_heapsnapandroid_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

//    while (1) {
//        int* test = new int[1]{1};
//        sleep(3);
//    }

//    int test = PLATFORM_SDK_VERSION;
    return env->NewStringUTF(hello.c_str());
}
