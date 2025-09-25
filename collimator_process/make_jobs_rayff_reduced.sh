colIdx=3
BASE_DATA_DIR=/data2/kneale/hk-software/collimator_sims/collimator_${colIdx}

if [ ! -e $BASE_DATA_DIR ];
then
    mkdir $BASE_DATA_DIR;
fi


for i in 0.975 0.9 0.825 0.78 0.765 0.7425 0.7275 0.7125 0.6375 0.5625 #### rayff

do

	for j in {0..19}
	do
	    file=$BASE_DATA_DIR/collimator_${colIdx}_rayff_${i}_${j}.root
	    if [ -f "$file" ]; then
                cp $BASE_DATA_DIR/../job_collimator_1_0.9_0.75_1.30.sh $BASE_DATA_DIR/jobtest/job_collimator_${colIdx}_rayff_${i}_${j}.sh
                cp $BASE_DATA_DIR/../condor_collimator_1.sub $BASE_DATA_DIR/jobtest/condor_collimator_${colIdx}_rayff_${i}_${j}.sub

		# change the file names in the job script
		sed -i "s/params_0.9_0.75_1.30/params_rayff_${i}/g" $BASE_DATA_DIR/jobtest/job_collimator_${colIdx}_rayff_${i}_${j}.sh
		sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${colIdx}_rayff_${i}_${j}/g" $BASE_DATA_DIR/jobtest/job_collimator_${colIdx}_rayff_${i}_${j}.sh
                sed -i "s/collimator_1/collimator_${colIdx}/g" $BASE_DATA_DIR/jobtest/job_collimator_${colIdx}_rayff_${i}_${j}.sh
                sed -i "/WCSim\s\$DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac\s\$DATA_DIR/params_0.9_0.75_1.30.mac/d" $BASE_DATA_DIR/jobtest/job_collimator_${colIdx}_rayff_${i}_${j}.sh

		# change the condor submission script
                sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${colIdx}_rayff_${i}_${j}/" $BASE_DATA_DIR/jobtest/condor_collimator_${colIdx}_rayff_${i}_${j}.sub
                sed -i "s/collimator_1_job/col_${colIdx}_rayff_${i}_${j}/" $BASE_DATA_DIR/jobtest/condor_collimator_${colIdx}_rayff_${i}_${j}.sub

	    fi
	done;
 #   fi
done;
