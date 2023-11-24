# Dockerfile to build Android application using Gradle
# ---

# How to Use
# ---
# Create a Image:
# $ docker build -t compile-apk .
# To compile the application, in the project directory, run:
# $ docker run -v $(pwd):/src compile-apk gradle build

# Versions Installed
# ---
# Gradle: 8.4.0
# Kotlin: 1.9.10
# Groovy: 3.0.17
# JVM: 17.0.9 (Eclipse Adoptium 17.0.9+9)
# OS: Linux 6.2.0-1016-azure amd64
# openjdk 17.0.9 2023-10-17
# OpenJDK Runtime Environment Temurin-17.0.9+9 (build 17.0.9+9)
# OpenJDK 64-Bit Server VM Temurin-17.0.9+9 (build 17.0.9+9, mixed mode, sharing)
# javac 17.0.9
# sdkmanager: 9.0


FROM gradle:8.4.0-jdk17 as gradle840

# RUN echo "1 - Testing Gradle installation" \
#     && gradle --version \
#     && echo "\n2 - Testing java installation" \
#     && java --version \
#     && echo "\n3 - Testing javac installation" \
#     && javac --version

ENV GRADLE_DIR=/opt/gradle/
ENV ANDROID_HOME=/usr/local/android_sdk
ENV ANDROID_SDK_ROOT=/usr/local/android_sdk
ENV ANDROID_BUILD_TOOLS_VERSION=33.0.1

ARG CMDLINE_TOOLS="cmdline-tools"
ARG CMDLINE_TOOLS_ZIP="${CMDLINE_TOOLS}.zip"
ARG CMDLINE_TOOLS_LAST="${ANDROID_HOME}/${CMDLINE_TOOLS}/latest"

ENV PATH="${CMDLINE_TOOLS_LAST}/bin:$PATH"

RUN echo "Downloading the sdkmanager command line" \
    && wget --no-verbose --output-document=${CMDLINE_TOOLS_ZIP} "https://dl.google.com/android/repository/commandlinetools-linux-9477386_latest.zip"

RUN echo "Installing sdkmanager" \
    && mkdir -p ${CMDLINE_TOOLS_LAST} \
    && unzip ${CMDLINE_TOOLS_ZIP} \
    && mv ${CMDLINE_TOOLS}/* "${CMDLINE_TOOLS_LAST}/" \
    && rm -r ${CMDLINE_TOOLS_ZIP} ${CMDLINE_TOOLS} \
    # for debugging
    # && echo "Testing sdkmanager installation" \
    # && ls -al ${ANDROID_HOME} \
    # && ls -al ${CMDLINE_TOOLS_LAST} \
    && sdkmanager --version

RUN echo "Configuring the sdkmanager" \
    && sdkmanager --install "build-tools;33.0.2" "cmdline-tools;latest" "ndk;21.4.7075529" \
    # for Android 9
    # && sdkmanager "platforms;android-28" \
    && sdkmanager "platforms;android-33" \
    && sdkmanager "build-tools;33.0.1" "platforms;android-33" \
    && sdkmanager --install "cmake;3.22.1" \
    && sdkmanager --install "ndk;25.2.9519653" \
    && yes | sdkmanager --licenses


WORKDIR /src
