FROM ubuntu:16.04

RUN \
  apt-get update && \
  apt-get -y upgrade && \
  apt-get install -y build-essential && \
  apt-get install -y software-properties-common && \
  apt-get install -y tmux curl git man unzip vim wget

ENV HOME /home
WORKDIR /home

ENV verilator_ver 3.904
ENV verilator_dir ${HOME}/verilator
ENV verilator_web http://www.veripool.org/ftp/verilator-${verilator_ver}.tgz
ENV verilator_tar ${verilator_dir}/verilator-${verilator_ver}.tar.gz

RUN mkdir -p ${verilator_dir}

RUN wget ${verilator_web} -O ${verilator_tar}
RUN tar xf ${verilator_tar} -C ${verilator_dir}

RUN cd ${HOME}

CMD ["bash"]
