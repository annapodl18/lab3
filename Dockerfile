FROM debian
COPY 3.cpp .
RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ 3.cpp -static -o 3
CMD ./3
