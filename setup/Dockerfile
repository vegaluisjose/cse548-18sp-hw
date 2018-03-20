FROM ubuntu:16.04

RUN \
  apt-get update && \
  apt-get -y upgrade && \
  apt-get install -y build-essential && \
  apt-get install -y software-properties-common && \
  apt-get install -y tmux curl git man unzip vim wget && \
  apt-get install -y flex bison

ENV HOME /home
WORKDIR /home

# verilator simulator
ENV verilator_ver 3.904
ENV verilator_top ${HOME}/verilator
ENV verilator_ins ${verilator_top}/install
ENV verilator_dir ${verilator_top}/verilator-${verilator_ver}
ENV verilator_web http://www.veripool.org/ftp/verilator-${verilator_ver}.tgz
ENV verilator_tar ${verilator_top}/verilator-${verilator_ver}.tar.gz

RUN mkdir -p ${verilator_top}
RUN mkdir -p ${verilator_ins}

RUN wget ${verilator_web} -O ${verilator_tar}
RUN tar xf ${verilator_tar} -C ${verilator_top}
RUN cd ${verilator_dir} && ./configure --prefix=${verilator_ins}
RUN make -C ${verilator_dir} verilator_bin
RUN make -C ${verilator_dir} installbin installdata

# ariane riscv-fesvr
ENV fesvr_dir ${HOME}/riscv-fesvr
ENV fesvr_ins ${HOME}/riscv-fesvr/install
ENV fesvr_bld ${HOME}/riscv-fesvr/build
RUN git clone https://github.com/pulp-platform/riscv-fesvr.git ${fesvr_dir}
RUN git -C ${fesvr_dir} checkout caffc16f703de16866f5d49daaaf3f474900b9a7 -b cse548
RUN mkdir -p ${fesvr_bld} ${fesvr_ins}
RUN cd ${fesvr_bld} && ../configure --prefix=${fesvr_ins}
RUN make -C ${fesvr_bld} install

RUN cd ${HOME}

CMD ["bash"]
