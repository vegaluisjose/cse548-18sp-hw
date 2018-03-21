# verilator_ins env-variable is defined in Dockerfile
verilator_bin = $(verilator_ins)/bin/verilator

ariane_top_module_name = ariane_wrapped

# ariane_dir env-variable is defined in Dockerfile
ariane_src_dir = $(ariane_dir)/src
ariane_tb_dir = $(ariane_dir)/tb
ariane_inc_dir = $(ariane_dir)/include

ariane_pkg_files = \
$(ariane_inc_dir)/ariane_pkg.sv \
$(ariane_inc_dir)/nbdcache_pkg.sv

ariane_vfiles = \
$(filter-out $(ariane_src_dir)/regfile.sv, $(wildcard $(ariane_src_dir)/*.sv)) \
$(ariane_src_dir)/util/cluster_clock_gating.sv \
$(ariane_src_dir)/util/behav_sram.sv \
$(ariane_src_dir)/axi_mem_if/axi2mem.sv \
$(ariane_tb_dir)/agents/axi_if/axi_if.sv

ariane_cfiles = \
$(ariane_tb_dir)/ariane_tb.cpp \
$(ariane_tb_dir)/simmem.cpp

hw_dir = $(abspath .)
out_dirname = out
out_dir = $(hw_dir)/$(out_dirname)

docker_hw_dir = /home/hw1
docker_out_dir = $(docker_hw_dir)/$(out_dirname)
docker_image_name = cse548
docker_cmd = docker run -v $(hw_dir):$(docker_hw_dir) -it $(docker_image_name)

default:
	$(docker_cmd) /usr/bin/make -C $(docker_hw_dir) build_ariane

run_docker:
	$(docker_cmd)

build_ariane: $(out_dir)/ariane

# fesvr_dir env-variable is define in Dockerfile
$(out_dir)/ariane:
	$(verilator_bin) --trace --cc --exe -Wno-fatal --unroll-count 256 --Wall \
	-CFLAGS "-I$(fesvr_dir) -std=c++11 -I${fesvr_dir}" \
	-LDFLAGS "-L$(fesvr_dir)/install/lib -lfesvr" \
	-Mdir $(docker_out_dir) --top-module $(ariane_top_module_name) +incdir+$(ariane_inc_dir) \
	$(ariane_pkg_files) $(ariane_vfiles) $(ariane_cfiles)
	cd $(docker_out_dir) && make -j -f V$(ariane_top_module_name).mk
