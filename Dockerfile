FROM gcc:latest
WORKDIR usr/src
COPY ./src/ .
RUN cmake -S .-B bulid/
RUN cmake --bulid bulid
CMD ["cd bulid", "cd debug", "project_main.exe" ]
