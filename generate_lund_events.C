{

  gSystem->CompileMacro("DisFunctions.C", "kf");
  gSystem->CompileMacro("GenFunctions.C", "kf");
  gSystem->CompileMacro("InclusiveRateAnalysis.C");
  t=new InclusiveRateAnalysis();
  /* 11 GeV beam energy */
  t->SetKinematicLimits( 5, 35, 0.5, 0.5, 10.9, 0.005, 75674, 11.0 );
  t->SetFile("cross_section_data/data_5_35_0.5_10.9_11.0GeV.dat");
  /* --------- */
  /* 6 GeV beam energy */
  // t->SetKinematicLimits( 5, 35, 0.5, 0.5, 6.0, 0.005, 46872, 6 );
  // t->SetFile("cross_section_data/data_5_35_0.5_6.0_6.0GeV.dat");
  /* --------- */
  t->PrepareOutput("");
  t->BookHistos();
  t->SetLuminosity( pow( 10, 35 ) );
  t->ReadDataFile();
  t->PlotCrossSectionDependences();
  t->GeneratePseudoData( 100000, 1000, "lund_files");
  t->CompareGenEventsToOriginal();
  t->SaveOutput();
  delete t;

}
