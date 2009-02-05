/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYREDUCE_H__
#define __MayaDM_POLYREDUCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyReduce : public PolyModifier
{
public:
public:
	PolyReduce(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyReduce"){}
	virtual ~PolyReduce(){}
	void setPercentage(double p)
	{
		if(p == 0) return;
		fprintf(mFile,"setAttr \".p\" %f;\n", p);

	}
	void setCompactness(double com)
	{
		if(com == 0.0) return;
		fprintf(mFile,"setAttr \".com\" %f;\n", com);

	}
	void setGeomWeights(double gwt)
	{
		if(gwt == 1) return;
		fprintf(mFile,"setAttr \".gwt\" %f;\n", gwt);

	}
	void setUvWeights(double uwt)
	{
		if(uwt == 0) return;
		fprintf(mFile,"setAttr \".uwt\" %f;\n", uwt);

	}
	void setColorWeights(double cwt)
	{
		if(cwt == 0) return;
		fprintf(mFile,"setAttr \".cwt\" %f;\n", cwt);

	}
	void setKeepQuadsWeight(double kqw)
	{
		if(kqw == 0) return;
		fprintf(mFile,"setAttr \".kqw\" %f;\n", kqw);

	}
	void setWeightCoefficient(double wc)
	{
		if(wc == 10000.0) return;
		fprintf(mFile,"setAttr \".wc\" %f;\n", wc);

	}
	void setVertexWeights(const doubleArray& vwt)
	{
		if(vwt.size == 0) return;
		fprintf(mFile,"setAttr \".vwt\" -type \"doubleArray\" ");
		vwt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setKeepBorder(bool kb)
	{
		if(kb == true) return;
		fprintf(mFile,"setAttr \".kb\" %i;\n", kb);

	}
	void setKeepMapBorder(bool kmb)
	{
		if(kmb == true) return;
		fprintf(mFile,"setAttr \".kmb\" %i;\n", kmb);

	}
	void setKeepHardEdge(bool khe)
	{
		if(khe == true) return;
		fprintf(mFile,"setAttr \".khe\" %i;\n", khe);

	}
	void setKeepOriginalVertices(bool kev)
	{
		if(kev == false) return;
		fprintf(mFile,"setAttr \".kev\" %i;\n", kev);

	}
	void setTriangulate(bool t)
	{
		if(t == true) return;
		fprintf(mFile,"setAttr \".t\" %i;\n", t);

	}
	void setCachingReduce(bool cr)
	{
		if(cr == false) return;
		fprintf(mFile,"setAttr \".cr\" %i;\n", cr);

	}
	void setBorder(double b)
	{
		if(b == .5) return;
		fprintf(mFile,"setAttr \".b\" %f;\n", b);

	}
	void setLine(double l)
	{
		if(l == .5) return;
		fprintf(mFile,"setAttr \".l\" %f;\n", l);

	}
	void setDetail(double d)
	{
		if(d == .5) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void getPercentage()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getCompactness()
	{
		fprintf(mFile,"\"%s.com\"",mName.c_str());

	}
	void getGeomWeights()
	{
		fprintf(mFile,"\"%s.gwt\"",mName.c_str());

	}
	void getUvWeights()
	{
		fprintf(mFile,"\"%s.uwt\"",mName.c_str());

	}
	void getColorWeights()
	{
		fprintf(mFile,"\"%s.cwt\"",mName.c_str());

	}
	void getKeepQuadsWeight()
	{
		fprintf(mFile,"\"%s.kqw\"",mName.c_str());

	}
	void getWeightCoefficient()
	{
		fprintf(mFile,"\"%s.wc\"",mName.c_str());

	}
	void getWeights(size_t wts_i)
	{
		fprintf(mFile,"\"%s.wts[%i]\"",mName.c_str(),wts_i);

	}
	void getVertexWeights()
	{
		fprintf(mFile,"\"%s.vwt\"",mName.c_str());

	}
	void getKeepBorder()
	{
		fprintf(mFile,"\"%s.kb\"",mName.c_str());

	}
	void getKeepMapBorder()
	{
		fprintf(mFile,"\"%s.kmb\"",mName.c_str());

	}
	void getKeepHardEdge()
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());

	}
	void getKeepOriginalVertices()
	{
		fprintf(mFile,"\"%s.kev\"",mName.c_str());

	}
	void getTriangulate()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getCachingReduce()
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());

	}
	void getBorder()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getLine()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getDetail()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
protected:
	PolyReduce(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYREDUCE_H__