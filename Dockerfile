FROM gcc:latest
WORKDIR usr/src
COPY ./src/ .
RUN apt-get update; apt-get install -y build-essential cmake
RUN cmake -S . -B build
RUN cmake --build build
EXPOSE 5555
CMD ["./build/fobar_DT" ]
