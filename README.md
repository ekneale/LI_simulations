# LI_simulations

Diffuser and collimator simulations and associated analysis for light-injection calibration system for Hyper-K.

# Diffuser simulations

The code in this directory covers the process of running simulations of diffusers on the Sheffield hep cluster using HK-WCSim, and performing data reduction to save only the quantities needed for saturation and single photoelectron studies.

__Quick start__

To use, do:

```./make_jobs_baseline.sh```

in the diffuser_simulations directory.

This will create directories for each diffuser specified in make\_jobs\_baseline.sh, and will a create job submission file (condor\_diffuser\_\*.sub), a job script (job\_diffuser\_\*.sh) and a parameters file (params\_0.9\_0.75\_1.30.mac), where \* represents the diffuser index, photon wavelength, time resolution (FWHM), and the number of photons per pulse. The parameters file specifies the default settings for Tyvek reflectivity, light attenuation and Rayleigh scattering in the HK detector.

__NB__ This will only work on the Sheffield HEP cluster, and should be altered to run elsewhere.

To run the simulation and data reduction, simply do 

```condor_submit condor*.sub```

This will handle the generation of macros to run the number of jobs set in the condor submission script. In each macro, the job index will be appended to the random seed for the simulation, so that each job uses a different random seed.

__User settings__

Job submission:

In the condor submission script, the user should set the following:

The ```WCSIMDIR``` environment variable should be set to the location of the root directory of the WCSim installation you wish to use.

The number of jobs you wish to run is set by change the value after ```queue```, which is set to ```queue 50``` to run 50 jobs by default.

You can also optionally change the job run requirements:

```
request_memory=8GB
maxjobretirementtime=1*3600
```

Diffuser characteristics:

The following diffuser characteristics should be set within make_baseline_jobs.sh:

```photonsperpulse``` the number of photons per pulse (after diffuser efficiency and attenuation in the optical fibres)

```wavelengths``` the photon wavelength for each of the diffusers being simulated

```pulsewidths``` the diffuser FWHM pulse width in ns

```pulses``` the number of pulses you wish to simulate per job run - this will be largely dictated by time and memory constraints

```diffusers``` the index of each diffuser being simulated, which must correspond to the index of the diffuser in the LightInjectorsDetails.json database in WCSim/data

The ```BASE_DATA_DIR``` directory where you want the output root files to be stored should also be defined in make_baseline_jobs.sh.

# Saturation Studies

Once you have run all of the diffuser simulations, you should hadd together all of the runs for each diffuser so that you have a single reduced_*.root file for each diffuser. 

There are currently two parts to the saturation studies:

1. plot_diffuser_output.C

2. pmtmapOD.C

Both of these currently require you to set the name of the hadded reduced_*.root file which is passed in the function initialisation. This should be changed/automated.

The first step - plot_diffuser_output.C - plots the mean number of photoelectrons (pe) per PMT and calculates the mean saturation distance, defined as the distance at which the mean number of pe per PMT is over the saturation threshold. The saturation threshold is currently set to 100 pe in 16 ns, limited by the digitisation constraints. It also plots the total number of pe per PMT and calcualates the saturation limit, defined as the distance at which the total number of pe per PMT is over the saturation threshold, for at least one PMT. 

These two values - the saturation distance and saturation limit - are then input into pmtmapOD.C. This calculates the percentage of PMTs which fall within the saturation distance and saturation limit, and plots a charge map of all of the PMTs in the detector, showing the positions of the diffusers (read from a list of diffuser positions) and rings marking in the saturation distance and saturation limit around them for visualisation of the percentage saturation coverage.

Currently the saturation distance, saturation limit, and percentage coverages are output to screen, although the percentage coverages are also output to a text file. At some point, this process will be improved so that the whole analysis runs automatically given an input file name from the command line.
