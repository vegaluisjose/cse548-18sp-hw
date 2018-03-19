hw_dir = $(abspath .)

verilator_bin = $(verilator_ins)/bin/verilator

docker_hw_dir = /home/hw0
docker_image_name = verilator
docker_cmd = docker run -v $(hw_dir):$(docker_hw_dir) -it $(docker_image_name)

src_dir = $(docker_hw_dir)/src

src_files = \
$(src_dir)/adder.v \
$(src_dir)/main.cc

out_dir = $(docker_hw_dir)/out

all:
	$(docker_cmd) /usr/bin/make -C $(docker_hw_dir) run

run: $(out_dir)/Vadder
	$<

$(out_dir)/Vadder: $(out_dir)/Vadder.mk
	make -C $(out_dir) -f Vadder.mk

$(out_dir)/Vadder.mk:
	$(verilator_bin) --cc --exe -Mdir $(out_dir) $(src_files) -o $(out_dir)/Vadder

clean:
	$(docker_cmd) /bin/rm -rf $(out_dir)
