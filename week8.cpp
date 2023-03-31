#include <jni.h>
#include <cmath>
#include <omp.h>

extern "C"
JNIEXPORT jdouble JNICALL Java_TextMenu_calculateMean(JNIEnv * env, jclass cls, jintArray arr)
{
    jint* numbers = env->GetIntArrayElements(arr, NULL);
    jsize len = env->GetArrayLength(arr);

    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < len; i++) {
        sum += numbers[i];
    }

    env->ReleaseIntArrayElements(arr, numbers, 0);

    return sum / len;
}

extern "C"
JNIEXPORT jdouble JNICALL Java_TextMenu_calculateSTDDev(JNIEnv * env, jclass cls, jintArray arr)
{
    jint* numbers = env->GetIntArrayElements(arr, NULL);
    jsize len = env->GetArrayLength(arr);

    double sum = 0.0;
    double mean = 0.0;
#pragma omp parallel for reduction(+:mean)
    for (int i = 0; i < len; i++) {
        mean += numbers[i];
    }
    mean /= len;

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < len; i++) {
        sum += (numbers[i] - mean) * (numbers[i] - mean);
    }

    env->ReleaseIntArrayElements(arr, numbers, 0);

    return sqrt(sum / (len - 1));
}
