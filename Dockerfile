FROM gcc:latest
WORKDIR usr/src
COPY ./src/ .
RUN g++ main.cpp app.cpp factory.cpp
CMD ["./a.out"]
