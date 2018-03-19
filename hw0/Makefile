top_name = adder
timeout_cycles = 10

verilator_bin = $(verilator_ins)/bin/verilator

hw_dir = $(abspath .)
docker_hw_dir = /home/hw0
docker_image_name = verilator
docker_cmd = docker run -v $(hw_dir):$(docker_hw_dir) -it $(docker_image_name)

src_dir = $(docker_hw_dir)/src

src_files = \
$(src_dir)/$(top_name).v \
$(src_dir)/main.cc

out_dir = $(docker_hw_dir)/out

all: clean
	$(docker_cmd) /usr/bin/make -C $(docker_hw_dir) run

run: $(out_dir)/V$(top_name)
	$<

$(out_dir)/V$(top_name): $(out_dir)/V$(top_name).mk
	make -C $(out_dir) -f V$(top_name).mk

$(out_dir)/V$(top_name).mk:
	$(verilator_bin) --cc --exe -Mdir $(out_dir) $(src_files) \
	-CFLAGS "-include V$(top_name).h -DVNAME=V$(top_name) -DTIMEOUT_CYCLES=$(timeout_cycles)" \
	-o $(out_dir)/V$(top_name)

clean:
	$(docker_cmd) /bin/rm -rf $(out_dir)
