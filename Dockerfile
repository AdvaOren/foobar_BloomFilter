FROM gcc:latest
WORKDIR usr/src
COPY ./src/ .
RUN apt-get update; apt-get install -y build-essential cmake
RUN cmake -S . -B bulid
RUN cmake --bulid bulid
WORKDIR bulid
WORKDIR debug
CMD ["project_main.exe" ]
