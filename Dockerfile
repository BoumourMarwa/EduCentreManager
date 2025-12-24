FROM ubuntu:20.04
RUN apt update && apt install -y \
    g++ \
    make

WORKDIR /app
COPY . .
RUN make
CMD ["make", "run"]
