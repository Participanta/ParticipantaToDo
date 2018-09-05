//
// Created by A17028 on 2018/2/1.
#include <android/log.h>
#include"JavaJni_TestJniInterface.h"
#include<string>
#include <stdio.h>

using namespace std;
JNIEXPORT jstring JNICALL Java_JavaJni_TestJniInterface_JavaCallC
  (JNIEnv *env, jclass jClass, jstring){
    string hello = "Hello from C++";
    int maxtimes=10;
    while(maxtimes--){
        __android_log_print(ANDROID_LOG_INFO, "nativelib", "Java Call C++");
        printf("%s","555555");
    }
    Java_JavaJni_TestJniInterface_CCallJava(env,jClass);
    return env->NewStringUTF(hello.c_str());
  }

JNIEXPORT void JNICALL Java_JavaJni_TestJniInterface_CCallJava
        (JNIEnv *env, jclass jClass){
    __android_log_print(ANDROID_LOG_INFO, "GetMethodID", "GetMethodID start");
    jclass clazz = env->FindClass("JavaJni/TestJniInterface");
    if (clazz == NULL)
        return ;

    jmethodID method = env->GetMethodID(clazz, "Test", "(Ljava/lang/String;)V");
    jstring data = env->NewStringUTF("hello java Im C++" );
    jobject jobt = env->AllocObject(clazz);
    env->CallVoidMethod(jobt,method,data);
    int maxtimes=10;
    while(maxtimes--){
        __android_log_print(ANDROID_LOG_INFO, "nativelib", "C++ Call Java");
        printf("%s","555555");
    }
    __android_log_print(ANDROID_LOG_INFO, "GetMethodID", "GetMethodID end");
}

JNIEXPORT jint JNICALL Java_JavaJni_TestJniInterface_add
        (JNIEnv *env, jclass jClass, jint a, jint b){

    return a+b;
}

JNIEXPORT void JNICALL Java_JavaJni_TestJniInterface_CGetJavaPrams
        (JNIEnv *env, jclass, jobject thiz){
    jclass clazz = env->FindClass("JavaJni/TestJniInterface");

//    jobject thiz = env->AllocObject(clazz);

    jfieldID field_mSNWriteBuffer = env->GetFieldID(clazz, "Snbuffer", "[B");
    jbyteArray jSnArray = (jbyteArray) env->GetObjectField(thiz, field_mSNWriteBuffer);
    if(jSnArray == NULL){
        return ;
    }
    int sn_length = env->GetArrayLength(jSnArray);
    jbyte* sn = env->GetByteArrayElements(jSnArray, 0);

    for (int i = 0; i < sn_length; ++i) {
        __android_log_print(ANDROID_LOG_INFO,"javaPram", "%c", (char)*(sn+i));
    }
}
