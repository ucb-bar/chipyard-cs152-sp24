echo "Installing matplotlib"
pip install matplotlib
echo "Fixing run_test.py"
sed -i "/rotation='-30',/d" ccbench/caches/run_test.py