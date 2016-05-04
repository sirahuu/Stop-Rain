#include <jni.h>
#include <dlfcn.h>
#include <Substrate.h>

class ServerLevel{
public:
void stopWeather();
void tick();
};
void (*_ServerLevel$tick)(ServerLevel*);
void ServerLevel$tick(ServerLevel* slevel){
_ServerLevel$tick(slevel);
slevel->stopWeather();
}
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
MSHookFunction((void*)&ServerLevel::tick,(void*)&ServerLevel$tick,(void**) &_ServerLevel$tick);
return JNI_VERSION_1_2;
}
