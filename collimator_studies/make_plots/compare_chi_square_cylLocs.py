import matplotlib.pyplot as plt

rayff_val1 = []
rayff_val_err1 = []
rayff_chi1 = []
rayff_err1 = []

rayff_val2 = []
rayff_val_err2 = []
rayff_chi2 = []
rayff_err2 = []

absff_val1 = []
absff_val_err1 = []
absff_chi1 = []
absff_err1 = []

absff_val2 = []
absff_val_err2 = []
absff_chi2 = []
absff_err2 = []

reflf_val1 = []
reflf_val_err1 = []
reflf_chi1 = []
reflf_err1 = []

reflf_val2 = []
reflf_val_err2 = []
reflf_chi2 = []
reflf_err2 = []

# TODO loop over the angles simulated

# Get values for first collimator angle
with open("colBarrel/collim_1.35/results/two_sample_chi_sq_colBarrel_allbottomPMTs.txt","r") as f1 , open("colBarrel/collim_1.35/results/two_sample_chi_sq_colBarrel_allbarrelPMTs.txt","r") as f2:

  for line, line2 in zip(f1,f2):
    print(line)
    vals = (line.strip().split(", "))
    # Get values for second collimator angle
    print(line2)
    vals2 = (line2.strip().split(", "))

    if "rayff" in line:
      chi2_1 = float(vals[2])
      chi2_2 = float(vals2[2])
      if chi2_1 >1000000 or chi2_2 > 1000000 : continue
      try:
        rayff_val1.append( ((float(vals[0].strip(".root").split("_")[-1])/0.75)-1.0)*100.0 )
      except:
        rayff_val1.append(0.)
      rayff_chi1.append( float(vals[2]) )
      rayff_err1.append(float(vals[3]))
      rayff_chi2.append( float(vals2[2]) )
      rayff_err2.append(float(vals2[3]))
      print(rayff_val1[-1], rayff_chi1[-1] ,rayff_err1[-1])
      print(rayff_val1[-1], rayff_chi2[-1], rayff_err2[-1])

    if "abwff" in line:
      chi2_1 = float(vals[2])
      chi2_2 = float(vals2[2])
      if chi2_1 >1000000 or chi2_2 > 1000000 : continue
      try:
        absff_val1.append( ((float(vals[0].strip(".root").split("_")[-1])/1.30)-1.0)*100.0 )
      except:
        absff_val1.append(0)
      absff_chi1.append( float(vals[2]) )
      absff_err1.append(float(vals[3]))
      absff_chi2.append( float(vals2[2]) )
      absff_err2.append(float(vals2[3]))
      print(absff_val1[-1], absff_chi1[-1] ,absff_err1[-1])
      print(absff_val1[-1], absff_chi2[-1], absff_err2[-1])

    if "refl" in line:
      chi2_1 = float(vals[2])
      chi2_2 = float(vals2[2])
      if chi2_1 >1000000 or chi2_2 > 1000000 : continue
      try:
        reflf_val1.append( ((float(vals[0].strip(".root").split("_")[-1])/0.9)-1.0)*100.0 )
      except:
        reflf_val1.append(0)
      reflf_chi1.append( float(vals[2]) )
      reflf_err1.append(float(vals[3]))
      reflf_chi2.append( float(vals2[2]) )
      reflf_err2.append(float(vals2[3]))
      print(reflf_val1[-1], reflf_chi1[-1], reflf_err1[-1] )
      print(reflf_val1[-1], reflf_chi2[-1], reflf_err2[-1])


## Plot of scattering
#plt.subplot(2,2,1)
plt.errorbar(rayff_chi1, rayff_chi2, xerr=rayff_err1, yerr=rayff_err2 ,label="scattering",linestyle='none',fmt='o',capsize=3,markersize=2)
plt.xlim([0,10])
plt.ylim([0,10])
#plt.yscale("log")
#plt.xscale("log")
plt.title("Scattering")
plt.xlabel("chi2/ndof barrel PMTs")
plt.ylabel("chi2/ndof bottom PMTs")
plt.show()

## Plot of absorption
#plt.subplot(2,2,2)
plt.errorbar( absff_chi1, absff_chi2, xerr=absff_err1, yerr=absff_err2, label = "absorption", linestyle='none' ,fmt='o',capsize=3,markersize=2)

plt.xlim([0,20])
plt.ylim([0,20])
#plt.yscale("log")
#plt.xscale("log")
plt.title("Absorption")
plt.xlabel("chi2/ndof barrel PMTs")
plt.ylabel("chi2/ndof bottom PMTs")
plt.show()

## Plot of Tyvek reflectivity
#plt.subplot(2,2,3)
plt.errorbar( reflf_chi1, reflf_chi2, xerr =reflf_err1, yerr=reflf_err2, label="reflectivity",linestyle='none',fmt='o',capsize=3, markersize=2)

#plt.xlim([0,500])
#plt.ylim([0,500])
#plt.yscale("log")
#plt.xscale("log")
plt.title("Reflectivity")
plt.xlabel("chi2/ndof barrel PMTs")
plt.ylabel("chi2/ndof bottom PMTs")
#plt.legend

plt.show()
