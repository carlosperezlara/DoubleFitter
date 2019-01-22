

Model1 *fitter1;

void FCN(Int_t& a, Double_t* b, Double_t &val, Double_t *par, Int_t e) {
  fitter1->FCN( a, b, val, par, e );
}

int fit() {
  fitter1 = new Model1;
  fitter1->SetMassHistogram( mass );
  fitter1->SetFlowHistogram( flow );
  fitter1->Init();
  fitter1->LoadIni( loadini.Data() );
  fitter1->Print( loadini.Data() );
  TVirtualFitter::SetDefaultFitter("Minuit");
  TVirtualFitter *minuit1 = TVirtualFitter::Fitter(NULL,fitter1->GetNumberOfParameters());
  minuit->SetFCN( FCN );
  fitter1->Fit( minuit1 );
  fitter1->SaveAs( saveAs.Data() );
  delete fitter;
  
  return 0;
}
