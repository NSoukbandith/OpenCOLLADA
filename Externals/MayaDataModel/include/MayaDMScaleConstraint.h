/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCALECONSTRAINT_H__
#define __MayaDM_SCALECONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
class ScaleConstraint : public Constraint
{
public:
	struct Target{
		double3 targetScale;
		matrix targetParentMatrix;
		double targetWeight;
		void write(FILE* file) const
		{
			targetScale.write(file);
			fprintf(file, " ");
			targetParentMatrix.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", targetWeight);
		}
	};
public:
	ScaleConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "scaleConstraint"){}
	virtual ~ScaleConstraint(){}
	void setTarget(size_t tg_i,const Target& tg)
	{
		fprintf(mFile,"setAttr \".tg[%i]\" ",tg_i);
		tg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetScale(size_t tg_i,const double3& ts)
	{
		fprintf(mFile,"setAttr \".tg[%i].ts\" -type \"double3\" ",tg_i);
		ts.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetScaleX(size_t tg_i,double tsx)
	{
		if(tsx == 1.0) return;
		fprintf(mFile,"setAttr \".tg[%i].ts.tsx\" %f;\n", tg_i,tsx);

	}
	void setTargetScaleY(size_t tg_i,double tsy)
	{
		if(tsy == 1.0) return;
		fprintf(mFile,"setAttr \".tg[%i].ts.tsy\" %f;\n", tg_i,tsy);

	}
	void setTargetScaleZ(size_t tg_i,double tsz)
	{
		if(tsz == 1.0) return;
		fprintf(mFile,"setAttr \".tg[%i].ts.tsz\" %f;\n", tg_i,tsz);

	}
	void setTargetParentMatrix(size_t tg_i,const matrix& tpm)
	{
		if(tpm == identity) return;
		fprintf(mFile,"setAttr \".tg[%i].tpm\" -type \"matrix\" ",tg_i);
		tpm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetWeight(size_t tg_i,double tw)
	{
		if(tw == 1.0) return;
		fprintf(mFile,"setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);

	}
	void setConstraintParentInverseMatrix(const matrix& cpim)
	{
		if(cpim == identity) return;
		fprintf(mFile,"setAttr \".cpim\" -type \"matrix\" ");
		cpim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffset(const double3& o)
	{
		fprintf(mFile,"setAttr \".o\" -type \"double3\" ");
		o.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetX(double ox)
	{
		if(ox == 1.0) return;
		fprintf(mFile,"setAttr \".o.ox\" %f;\n", ox);

	}
	void setOffsetY(double oy)
	{
		if(oy == 1.0) return;
		fprintf(mFile,"setAttr \".o.oy\" %f;\n", oy);

	}
	void setOffsetZ(double oz)
	{
		if(oz == 1.0) return;
		fprintf(mFile,"setAttr \".o.oz\" %f;\n", oz);

	}
	void getTarget(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i]\"",mName.c_str(),tg_i);

	}
	void getTargetScale(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].ts\"",mName.c_str(),tg_i);

	}
	void getTargetScaleX(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].ts.tsx\"",mName.c_str(),tg_i);

	}
	void getTargetScaleY(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].ts.tsy\"",mName.c_str(),tg_i);

	}
	void getTargetScaleZ(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].ts.tsz\"",mName.c_str(),tg_i);

	}
	void getTargetParentMatrix(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tpm\"",mName.c_str(),tg_i);

	}
	void getTargetWeight(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tw\"",mName.c_str(),tg_i);

	}
	void getConstraintParentInverseMatrix()
	{
		fprintf(mFile,"\"%s.cpim\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOffsetX()
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());

	}
	void getOffsetY()
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());

	}
	void getOffsetZ()
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());

	}
	void getConstraintScale()
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());

	}
	void getConstraintScaleX()
	{
		fprintf(mFile,"\"%s.cs.csx\"",mName.c_str());

	}
	void getConstraintScaleY()
	{
		fprintf(mFile,"\"%s.cs.csy\"",mName.c_str());

	}
	void getConstraintScaleZ()
	{
		fprintf(mFile,"\"%s.cs.csz\"",mName.c_str());

	}
	void getRestScale()
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());

	}
	void getRestScaleX()
	{
		fprintf(mFile,"\"%s.rs.rsx\"",mName.c_str());

	}
	void getRestScaleY()
	{
		fprintf(mFile,"\"%s.rs.rsy\"",mName.c_str());

	}
	void getRestScaleZ()
	{
		fprintf(mFile,"\"%s.rs.rsz\"",mName.c_str());

	}
protected:
	ScaleConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SCALECONSTRAINT_H__