# GatorLAND: ETL

This project implements the ETL for loading the graph operand to traverse using the approximate graph matching.
For this reason, there are some third party dependencies in the `third_party` folder. Some require additional setup, that is explained in the following subsection

## Dependencies 
### RocksDB

Within GNU/Linux, use the following command for installing the dependencies for RocksDB

```bash    
sudo apt-get install -y libsnappy-dev libgflags-dev zlib1g-dev libbz2-dev liblz4-dev libzstd-dev zlib1g-dev
```

## Running the ETL

In order to run the ETL, make sure that the default `TMPFILE` in your file system has enough memory for
loading the temporary data, sorting it and then preparing the loading of the final data representation. Therefore,
In your disk you will need (in the worst case scenario) 3 times the space required to store the original data.
Therefore, choose your default `TMPDIR` wisely and, eventually, set the following environment variable:

```bash
export TMPDIR=/path/to/your/custom/tmpdir
```