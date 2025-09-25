colIdx=0
BASE_DATA_DIR=/data2/kneale/hk-software/collimator_sims/collimator_${colIdx}

if [ ! -e $BASE_DATA_DIR ];
then
    mkdir $BASE_DATA_DIR;
fi
if [ ! -e $BASE_DATA_DIR/logs ];
then
    mkdir $BASE_DATA_DIR/logs;
fi

cp $BASE_DATA_DIR/../params_0.9_0.75_1.30.mac $BASE_DATA_DIR/params_baseline.mac

for j in {0..19}
do
    file=$BASE_DATA_DIR/reduced_collimator_${colIdx}_baseline.root
    if [ -f "$file" ]
    then
	echo "$file exists"
    else
	cp $BASE_DATA_DIR/../macro_collimator_1_0.9_0.75_1.30.mac $BASE_DATA_DIR/macro_collimator_${colIdx}_baseline_${j}.mac
	cp $BASE_DATA_DIR/../job_collimator_1_0.9_0.75_1.30.sh $BASE_DATA_DIR/job_collimator_${colIdx}_baseline_${j}.sh
	cp $BASE_DATA_DIR/../condor_collimator_1.sub $BASE_DATA_DIR/condor_collimator_${colIdx}_baseline_${j}.sub

	# change the seed and the wcsim output filename in the macro
	sed -i "s/seed 3254/seed 3254$j/" $BASE_DATA_DIR/macro_collimator_${colIdx}_baseline_${j}.mac
	sed -i "s/collimator_1_0.9_0.75_1.30.root/collimator_${colIdx}_baseline_${j}.root/" $BASE_DATA_DIR/macro_collimator_${colIdx}_baseline_${j}.mac
        sed -i "s/injectorIdx 1/injectorIdx ${colIdx}/g" $BASE_DATA_DIR/macro_collimator_${colIdx}_baseline_${j}.mac

	# change the file names in the job script
        sed -i "s/params_0.9_0.75_1.30.mac/params_baseline.mac/g" $BASE_DATA_DIR/job_collimator_${colIdx}_baseline_${j}.sh
	sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${colIdx}_baseline_${j}/g" $BASE_DATA_DIR/job_collimator_${colIdx}_baseline_${j}.sh
        sed -i "s/collimator_1/collimator_${colIdx}/g" $BASE_DATA_DIR/job_collimator_${colIdx}_baseline_${j}.sh

	# change the condor submission script
	sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${colIdx}_baseline_${j}/" $BASE_DATA_DIR/condor_collimator_${colIdx}_baseline_${j}.sub
	sed -i "s/collimator_1_job/col_${colIdx}_baseline_${j}/" $BASE_DATA_DIR/condor_collimator_${colIdx}_baseline_${j}.sub

    fi
done;
