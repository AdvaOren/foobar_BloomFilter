FROM gcc:latest
WORKDIR usr/src
COPY ./src/ .
RUN g++ main.cpp
CMD ["./a.out"]
