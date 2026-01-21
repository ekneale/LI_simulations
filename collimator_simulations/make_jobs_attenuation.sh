photonsperpulse=(1000000 1000000)
wavelengths=(365.0 365.0)
pulsewidths=(10.0 10.0)
pulses=(10 10)
collimators=(10 13)

for laserIdx in {0..1}
do
    for abwff in 1.69 1.56 1.43 1.352 1.326 1.287 1.261 1.235 1.105 0.975
    do
        collimatorIdx=${collimators[laserIdx]}
        wl=${wavelengths[laserIdx]}
        ppp=${photonsperpulse[laserIdx]}
        pw=${pulsewidths[laserIdx]}
        npulse=${pulses[laserIdx]}
        
        BASE_DATA_DIR=/data2/kneale/hk-software/collimator_sims/collimator_${collimatorIdx}
        JOB_GENERATION_DIR=/data2/kneale/hk-software/LI_simulations/collimator_simulations
 
        if [ ! -e $BASE_DATA_DIR ];
        then
            mkdir $BASE_DATA_DIR;
        fi
        if [ ! -e $BASE_DATA_DIR/logs ];
        then
            mkdir $BASE_DATA_DIR/logs;
        fi
 
        cp $JOB_GENERATION_DIR/params_0.9_0.75_1.30.mac $BASE_DATA_DIR/params_abwff_${abwff}.mac
        sed -i "s/abwff\s1.30/abwff ${abwff}/" $BASE_DATA_DIR/params_abwff_${abwff}.mac
 
        cp $JOB_GENERATION_DIR/job_collimator_1_0.9_0.75_1.30.sh $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        cp $JOB_GENERATION_DIR/condor_collimator_1.sub $BASE_DATA_DIR/condor_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sub
        
        # change the file names in the job script
        sed -i "s/\/macro_collimator_1_0.9_0.75_1.30.mac/\/macro_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}_\${CONDOR_JOB_NUM}.mac/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/\/collimator_1_0.9_0.75_1.30.root/\/collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}_\${CONDOR_JOB_NUM}.root/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/reduced_collimator_1_0.9_0.75_1.30.root/reduced_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}_\${CONDOR_JOB_NUM}.root/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/\$BASE_DATA_DIR\/collimator_1/\$BASE_DATA_DIR\/collimator_${collimatorIdx}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/injectorDetector OD/injectorDetector OD_${collimatorIdx}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/injectorIdx 1/injectorIdx ${collimatorIdx}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/injectorWavelength 400/injectorWavelength ${wl}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/injectorPulseWidth 2/injectorPulseWidth ${pw}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/nphotons 2/nphotons ${ppp}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
        sed -i "s/beamOn 2/beamOn ${npulse}/g" $BASE_DATA_DIR/job_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sh
 
        # change the condor submission script
        sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}/" $BASE_DATA_DIR/condor_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sub
        sed -i "s/collimator_1_job/collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}/" $BASE_DATA_DIR/condor_collimator_${collimatorIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_abwff_${abwff}.sub

    done;
done;
