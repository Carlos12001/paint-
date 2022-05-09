//
// Created by carlo on 4/30/22.
//

#include "utilities.h"

void Utilities::callCow() {
    LOG(INFO) << "I tried to call cow." << endl;
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
    FLAGS_colorlogtostderr = true;  // Set log color
    FLAGS_logbufsecs = 0;  // Set log output speed(s)
    FLAGS_max_log_size = 1024;  // Set max log file size
    FLAGS_stop_logging_if_full_disk = true;  // If disk is full
}

void Utilities::finishLog() {
    google::ShutdownGoogleLogging();
}