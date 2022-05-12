//
// Created by carlo on 4/30/22.
//

#include "utilities.h"

void Utilities::callCow() {
    printMessageInfo("Hellow");
    system("cowsay Welcome to Paint++!");
}

void Utilities::startLog(char* argv[]){
    if(getIsStartedLog()){
        return;
    }
    else{
        getIsStartedLog() = true;
    }
    char *cwd = get_current_dir_name();
    google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::GLOG_INFO, cwd);
    google::SetStderrLogging(google::GLOG_INFO);
    google::SetLogFilenameExtension(".log");
    google::EnableLogCleaner(1);
    FLAGS_colorlogtostderr = true;  // Set log color
    FLAGS_logbufsecs = 0;  // Set log output speed(s)
    FLAGS_max_log_size = 10;  // Set max log file size
    FLAGS_stop_logging_if_full_disk = true;  // If disk is full
}

void Utilities::finishLog() {
    google::ShutdownGoogleLogging();
}

void Utilities::printMessageInfo(string message) {
    LOG(INFO) << message;

}

void Utilities::printMessageWarning(string message) {
    LOG(WARNING) << message;
}

void Utilities::printMessageError(string message) {
    LOG(ERROR) << message;
}

void Utilities::printMessageFatal(string message) {
    LOG(FATAL) << message;
}
