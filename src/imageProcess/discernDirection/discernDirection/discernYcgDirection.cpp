﻿#include "discernYcgDirection.h"
#include "system/tool/halconTool.h"

namespace TIGER_ProcessTool
{
    using namespace HalconCpp;
    bool CYcgDiscern::processUnionRegion(const HalconCpp::HObject &p_image, const HalconCpp::HObject &p_roiRegion, QSize p_imageSize)
    {
        m_error.clear();
        try
        {
            //********得到最靠近接近开关的延长杆
            ReduceDomain(p_image, p_roiRegion, &m_hObject);
            Threshold(m_hObject, &m_hObject, 210, 255);
            Connection(m_hObject, &m_hObject);

            //得到中间的区域
            HTuple areaRoi, rowRoi, columnRoi;
            AreaCenter(p_roiRegion, &areaRoi, &rowRoi, &columnRoi);
            SelectShape(m_hObject, &m_hObject, "column", "and", columnRoi - 30, columnRoi + 30);

            //去除多余区域
            SelectShape(m_hObject, &m_hObject, "area", "and", 1000, 99999999);
            ClosingCircle(m_hObject, &m_hObject, 10);
            FillUp(m_hObject, &m_hObject);
            Connection(m_hObject, &m_hObject);

            //获得最近的工件
            HTuple areaAll, rowAll, columnAll, numberAll, i, j;
            AreaCenter(m_hObject, &areaAll, &rowAll, &columnAll);
            CountObj(m_hObject, &numberAll);
            {
                HTuple endI = numberAll - 1;
                HTuple stepI = 1;
                for (i = 0; i.Continue(endI, stepI); i += stepI)
                {
                    HTuple endJ = (numberAll - i) - 2;
                    HTuple stepJ = 1;
                    for (j = 0; j.Continue(endJ, stepJ); j += stepJ)
                    {
                        if (0 != (int(HTuple(rowAll[j]) > HTuple(rowAll[j + 1]))))
                        {
                            HTuple ROW, COL;
                            ROW = HTuple(rowAll[j]);
                            rowAll[j] = HTuple(rowAll[j + 1]);
                            rowAll[j + 1] = ROW;

                            COL = HTuple(columnAll[j]);
                            columnAll[j] = HTuple(columnAll[j + 1]);
                            columnAll[j + 1] = COL;
                        }
                    }
                }
            }
            HObject selectedRegionsOriginal;
            SelectShape(m_hObject, &selectedRegionsOriginal, "row", "and", HTuple(rowAll[numberAll - 1]), p_imageSize.height());

            //对区域进行处理
            HObject selectedRegionsNear;
            OpeningCircle(selectedRegionsOriginal, &selectedRegionsNear, 3.5);
            Connection(selectedRegionsNear, &selectedRegionsNear);
            AreaCenter(selectedRegionsNear, &areaAll, &rowAll, &columnAll);
            SelectShape(selectedRegionsNear, &selectedRegionsNear, "area", "and", areaAll.TupleMax(), areaAll.TupleMax());

            FillUp(selectedRegionsNear, &selectedRegionsNear);
            ShapeTrans(selectedRegionsNear, &selectedRegionsNear, "convex");

            //********判断方向
            //得到小面积区域两端区域的长度比值
            HTuple rowNear1, columnNear1, rowNear2, columnNear2;
            SmallestRectangle1(selectedRegionsNear, &rowNear1, &columnNear1, &rowNear2, &columnNear2);

            HObject RectangleBehind, RegionIntersectionBehind;
            HTuple AreaBehind, RowBehind, ColumnBehind, RowBehind1, ColumnBehind1, RowBehind2, ColumnBehind2, LengthBehind;
            GenRectangle1(&RectangleBehind, rowNear1, columnNear1, rowNear1 + 10, columnNear2);
            Intersection(selectedRegionsNear, RectangleBehind, &RegionIntersectionBehind);
            AreaCenter(RegionIntersectionBehind, &AreaBehind, &RowBehind, &ColumnBehind);
            SmallestRectangle1(RegionIntersectionBehind, &RowBehind1, &ColumnBehind1, &RowBehind2, &ColumnBehind2);
            LengthBehind = ColumnBehind2 - ColumnBehind1;

            HObject RectangleFront, RegionIntersectionFront;
            HTuple AreaFront, RowFront, ColumnFront, RowFront1, ColumnFront1, RowFront2, ColumnFront2, LengthFront;
            GenRectangle1(&RectangleFront, rowNear2 - 10, columnNear1, rowNear2, columnNear2);
            Intersection(selectedRegionsNear, RectangleFront, &RegionIntersectionFront);
            AreaCenter(RegionIntersectionFront, &AreaFront, &RowFront, &ColumnFront);
            SmallestRectangle1(RegionIntersectionFront, &RowFront1, &ColumnFront1, &RowFront2, &ColumnFront2);
            LengthFront = ColumnFront2 - ColumnFront1;

            HTuple lengthRadio1, lengthRadio2, lengthRadi;
            lengthRadio1 = LengthFront / (LengthBehind.TupleReal());
            lengthRadio2 = LengthBehind / (LengthFront.TupleReal());
            lengthRadi = lengthRadio1;
            if (0 != (int(lengthRadio2 < lengthRadio1)))
            {
                lengthRadi = lengthRadio2;
            }

            //对紧挨着的件进行处理
            if (0 != (int(lengthRadi > 0.8)))
            {
                HTuple midDistance;
                midDistance = (rowNear2 - rowNear1) / 2;
                GenRectangle1(&m_hObject, (rowNear1 + midDistance) - 5, columnNear1, (rowNear1 + midDistance) + 5, columnNear2);
                Intersection(selectedRegionsOriginal, m_hObject, &RegionIntersectionBehind);
                AreaCenter(RegionIntersectionBehind, &AreaBehind, &RowBehind, &ColumnBehind);
                SmallestRectangle1(RegionIntersectionBehind, &RowBehind1, &ColumnBehind1, &RowBehind2, &ColumnBehind2);
            }

            //根据前后区域面积判断方向
            if (0 != (int(AreaFront > AreaBehind)))
            {
                m_direction = false;
            }
            else
            {
                m_direction = true;
            }
            return true;
        }
        catch (HException &except)
        {
            m_error = except.ErrorMessage().Text();
        }
        return false;
    }
};