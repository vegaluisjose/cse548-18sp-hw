dockerfile = $(abspath .)/Dockerfile
docker_image_name = verilator

work_dirname = workdir
work_dir = $(abspath .)/$(work_dirname)

verilator_version = 3.904

build:
	docker build -f $(dockerfile) -t $(docker_image_name) .

run:
	docker run -it $(docker_image_name)
