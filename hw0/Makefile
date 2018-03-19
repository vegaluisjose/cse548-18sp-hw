top_name = adder
timeout_cycles = 10
#sim_type = run # without waveform
sim_type = run_debug # with waveform

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
vcd_file = $(out_dir)/$(top_name).vcd

default: clean
	$(docker_cmd) /usr/bin/make -C $(docker_hw_dir) $(sim_type)

run: $(out_dir)/V$(top_name)
	$<

run_debug: $(out_dir)/V$(top_name)_debug
	$<

$(out_dir)/V$(top_name):
	$(verilator_bin) --cc --exe -Mdir $(out_dir) $(src_files) \
	-CFLAGS "-include V$(top_name).h -DVNAME=V$(top_name) -DTIMEOUT_CYCLES=$(timeout_cycles)" \
	-o $(out_dir)/V$(top_name)
	make -C $(out_dir) -f V$(top_name).mk

$(out_dir)/V$(top_name)_debug:
	$(verilator_bin) --trace --cc --exe -Mdir $(out_dir) $(src_files) \
	-CFLAGS "-include V$(top_name).h -DVNAME=V$(top_name) -DVM_TRACE" \
	-CFLAGS "-DVCD_FILE=$(vcd_file) -DTIMEOUT_CYCLES=$(timeout_cycles)" \
	-o $(out_dir)/V$(top_name)_debug
	make -C $(out_dir) -f V$(top_name).mk

clean:
	$(docker_cmd) /bin/rm -rf $(out_dir)
