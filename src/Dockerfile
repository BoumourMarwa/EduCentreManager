FROM ubuntu:20.04
RUN apt update && apt install -y \
    g++ \
    make
WORKDIR /app
COPY . .
RUN g++ -std=c++11 *.cpp -o gestion-centre
CMD ["./gestion-centre"]
