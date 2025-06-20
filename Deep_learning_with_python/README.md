## Build Docker Container for Deep Learning
```shell
docker build -t deep_learning .
```

## Run Docker Container
 - powershell
```shell
docker run -it --rm -v ${PWD}:/app -p 8888:8888 deep_learning
```
 - cmd
```shell
docker run -it --rm -v %cd%:/app -p 8888:8888 deep_learning
```

## Activate the base environment
```shell
conda activate base
```
```shell
conda create -n myenv python=3.10
```
```shell
conda activate myenv
```

## Start Jupyter Notebook for browser
```shell
jupyter notebook --ip=0.0.0.0 --no-browser --allow-root
```