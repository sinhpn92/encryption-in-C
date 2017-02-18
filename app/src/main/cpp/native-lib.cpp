#include <jni.h>
#include <string>
#include "md5.h"

extern "C"
jstring
Java_test_sinhpn_md5test_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */, jstring data) {
    char *cstr = (char *) (env)->GetStringUTFChars(data, 0);

    MD5_CTX context = {0};
    MD5Init(&context);
    MD5Update(&context, (unsigned char *) cstr, strlen(cstr));
    unsigned char dest[16] = {0};
    MD5Final(dest, &context);
    env->ReleaseStringUTFChars(data, cstr);

    int i;
    char destination[32] = {0};
    for (i = 0; i < 16; i++) {
        sprintf(destination, "%s%02x", destination, dest[i]);
    }
    return env->NewStringUTF(destination);
}
