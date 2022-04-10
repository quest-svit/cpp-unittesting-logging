FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
	gcc\
	liblog4cxx10-dev \
	libcppunit-dev \
	make \
    g++

COPY . /app
WORKDIR /app
CMD ["make", "all"]
	
